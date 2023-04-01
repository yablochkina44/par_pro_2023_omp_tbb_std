// Copyright 2023 Kandrin Alexey
#include <algorithm>
#include <cassert>
#include "../../../modules/task_1/kandrin_a_component_marking/component_marking.h"

#pragma region HelperClassesImplementation

//=============================================================================
// Function : WorkSplitter::WorkSplitter
// Purpose  : Constructor.
//=============================================================================
WorkSplitter::WorkSplitter(size_t work, size_t workerCount)
    : m_workDistribution(workerCount, 0) {
  if (work <= workerCount) {
    for (size_t currentWorker = 0; currentWorker < work; ++currentWorker) {
      m_workDistribution[currentWorker] = 1;
    }
  } else {
    for (size_t currentWorker = 0; work != 0; ++currentWorker) {
      size_t workForCurrentWorker = work / workerCount;
      m_workDistribution[currentWorker] = work / workerCount;
      work -= workForCurrentWorker;
      workerCount -= 1;
    }
  }
}

//=============================================================================
// Function : GetPartWork
// Purpose  : Determining how much work a worker should do.
//=============================================================================
size_t WorkSplitter::GetPartWork(size_t workerNumber) const {
  return m_workDistribution[workerNumber];
}

#pragma endregion HelperClassesImplementation


namespace {
// максимальное допустимое число компонент связности на изображении
constexpr size_t maxLabelCount =
    10000;  

// Parent - массив для хранения меток, имеющий древовидную структуру.
// В этом массиве индекс элемента следует интерпретировать как значение метки,
// А значение по этому индексу - это значение родительской метки.
// То есть parent[метка_1] == родительская_метка_для_метки_1
// Если у метки нет родительской метки, то вместо значения родительской метки записывается 0.
using Parent = std::vector<Label>;

// Поиск родительской метки для заданной метки множества
Label FindParent(Label label, const Parent& parent) {
  while (parent[label] != 0) {
    label = parent[label];
  }
  return label;
}

// Объединение двух множеств
void Union(Label x, Label y, Parent& parent) {
  x = FindParent(x, parent);
  y = FindParent(y, parent);
  if (x != y) {
    parent.at(y) = x;
  }
}

struct Position {
  size_t x, y;
  Position(size_t x, size_t y) : x(x), y(y) {}
};

std::vector<Position> GetPriorNeighbors(const BinaryImage& image, size_t i, size_t j) {
  // получение 2-ех соседей (северного и западного при 4-связности)
  std::vector<Position> result;
  if (image.empty()) return result;

  // верхний сосед
  if (i > 0) {
    result.emplace_back(i - 1, j);
  }

  // левый сосед
  if (j > 0) {
    result.emplace_back(i, j - 1);
  }

  return result;
}

// Получить (уже присвоенные) метки
std::vector<BinaryPixel> GetLabels(
    const LabelImage& image,
    const std::vector<Position>& priorNeighbors) {
  std::vector<BinaryPixel> result;
  for (auto && position : priorNeighbors) {
    size_t i = position.x;
    size_t j = position.y;
    if (image[i][j] != 0) result.push_back(image[i][j]);
  }
  return result;
}

// Получить маркировку компонент связности (последовательная реализация)
LabelImage GetComponentMarkingSeqImp(const BinaryImage& source) {
  LabelImage result(source.GetRowCount(), source.GetColCount(), 0);

  Parent parent(maxLabelCount, 0);
  Label label = 1;

  Label m = 0;
  for (size_t i = 0; i < source.GetRowCount(); ++i) {
    for (size_t j = 0; j < source.GetColCount(); ++j) {
      if (source[i][j] == 1) {
        auto priorNeighbors = GetPriorNeighbors(source, i, j);
        auto labels = GetLabels(result, priorNeighbors);
        if (labels.empty()) {
          m = label;
          label++;
        } else {
          m = *std::min_element(labels.begin(), labels.end());
        }
        result[i][j] = m;
        for (auto label : labels) {
          if (label != m) {
            Union(m, label, parent);
          }
        }
      }
    }
  }

  for (size_t i = 0; i < source.GetRowCount(); ++i) {
    for (size_t j = 0; j < source.GetColCount(); ++j) {
      if (source[i][j] == 1) {
        result[i][j] = FindParent(result[i][j], parent);
      }
    }
  }

  return result;
}

// Метод исправляет значения элементов в массиве arr таким образом,
// чтобы множество значений элементов массива не имело "пропусков".
// Например, если множество значений элементов массива - {1, 3, 7, 10},
// То оно превратится в {1, 2, 3, 4}
// Соответственно, массив arr, равный {1, 3, 10, 7, 1, 3, 10, 7, 1} превратится
// в {1, 2, 4, 3, 1, 2, 4, 3, 1}
void FixNumeration(Label* arr, size_t size) {
  static_assert(
      std::is_unsigned<std::remove_reference_t<decltype(*arr)>>::value,
      "This algorithm assumes that the label is unsigned");

  assert(arr != nullptr);
  if (arr == nullptr) return;

  std::vector<bool> isLabelExist(maxLabelCount, false);
  for (size_t i = 0; i < size; ++i) {
    assert(arr[i] <
           isLabelExist.size());  // предполагается, что в массиве arr сейчас
                                  // возможны от 0 до maxLabelCount
    isLabelExist[arr[i]] = true;
  }

  // Получение значения максимальной метки (для оптимизации следующего цикла)
  Label maxLabel = 0;
  for (size_t i = 0; i < size; ++i) {
    if (arr[i] > maxLabel) {
      maxLabel = arr[i];
    }
  }

  // Получение списка замен

  // Структура для замены
  struct Replace {
    Label before; // предыдущее значение метки (которое нужно поменять)
    Label after; // новое значение метки (на которое нужно поменять)

    Replace(BinaryPixel before, BinaryPixel after)
        : before(before), after(after) {}
  };
  std::vector<Replace> replaceArr; // список замен

  Label currentNumber = 1;  // переменная для нумерации
  for (Label currentLabel = 1; currentLabel <= maxLabel;) {
    // currentLabel - значение текущей метки
    // если такой метки не существует, то идем до ближайшей существующей метки
    // В этом цикле мы не можем выйти за пределы допустимого диапазона [1;
    // maxLabel], потому что метка maxLabel обязательно существует.
    while (!isLabelExist[currentLabel]) ++currentLabel;

    if (currentLabel != currentNumber) {
      // если текущая метка не равна текущему номеру, то добавляем "замену" в
      // список замен
      replaceArr.emplace_back(currentLabel, currentNumber);
    }

    ++currentLabel;
    ++currentNumber;
  }

  for (auto && replace : replaceArr) {
    for (size_t i = 0; i < size; ++i) {
      if (arr[i] == replace.before) arr[i] = replace.after;
    }
  }
}
}  // namespace

template<>
LabelImage GetComponentMarking<ExecutionPolicy::Sequential>(const BinaryImage& sourceImage) {
  auto result = GetComponentMarkingSeqImp(sourceImage);
  FixNumeration(result.data(), result.GetRowCount() * result.GetColCount());
  return result;
}
