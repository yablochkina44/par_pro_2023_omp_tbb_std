// Copyright 2023 Mironov Nikita
#include "../../../modules/task_1/mironov_n_trapezoid_method/trapezoid.h"

double d1_method(
    double (*f)(std::vector<double>),
    const std::vector<std::pair<double, double>>& bounds,
    int N) {
    double h = (bounds[0].second - bounds[0].first)/N;

    double x = bounds[0].first + h;

    double result = 0;

    result += (h/2) * (f({bounds[0].first}) + f({bounds[0].second}));

    for (int i = 1; i < N; i++) {
        result += h * f({x});
        x += h;
    }

    return result;
}

double d2_method(
    double (*f)(std::vector<double>),
    const std::vector<std::pair<double, double>>& bounds,
    int N) {
    double h_for_x = (bounds[0].second - bounds[0].first)/N;
    double h_for_y = (bounds[1].second - bounds[1].first)/N;

    double x = 0;
    double y = 0;

    double result = 0;

    result += (h_for_x/2) * (h_for_y/2) *
        (f({bounds[0].first, bounds[1].first}) +
        f({bounds[0].second, bounds[1].second}) +
        f({bounds[0].first, bounds[1].second}) +
        f({bounds[0].second, bounds[1].first}));

    for (int i = 0; i <= N; i++) {
        x = bounds[0].first + h_for_x * i;
        for (int j = 0; j <= N; j++) {
            y = bounds[1].first + h_for_y * j;

            result += (h_for_x * h_for_y) * f({x, y});
        }
    }

    for (int i = 1; i < N; i++) {
        x = bounds[0].first + h_for_x * i;

        result += (h_for_y/2) * (f({x, bounds[1].first}) +
        f({x, bounds[1].second}));
    }

    for (int j = 1; j < N; j++) {
        y = bounds[0].first + h_for_y * j;

        result += (h_for_x/2) * (f({bounds[0].first, y}) +
        f({bounds[0].second, y}));
    }

    return result;
}

double d3_method(
    double (*f)(std::vector<double>),
    const std::vector<std::pair<double, double>>& bounds,
    int N) {
    double h_for_x = (bounds[0].second - bounds[0].first)/N;
    double h_for_y = (bounds[1].second - bounds[1].first)/N;
    double h_for_z = (bounds[2].second - bounds[2].first)/N;

    double x = 0;
    double y = 0;
    double z = 0;

    double result = 0;

    result += (h_for_x/2) * (h_for_y/2) * (h_for_z/2) *
        (f({bounds[0].first, bounds[1].first, bounds[2].first}) +
        f({bounds[0].first, bounds[1].second, bounds[2].first}) +
        f({bounds[0].first, bounds[1].first, bounds[2].second}) +
        f({bounds[0].first, bounds[1].second, bounds[2].second}) +
        f({bounds[0].second, bounds[1].first, bounds[2].first}) +
        f({bounds[0].second, bounds[1].second, bounds[2].first}) +
        f({bounds[0].second, bounds[1].first, bounds[2].second}) +
        f({bounds[0].second, bounds[1].second, bounds[2].second}));
    for (int i = 0; i <= N; i++) {
        x = bounds[0].first + h_for_x * i;
        for (int j = 0; j <= N; j++) {
            y = bounds[1].first + h_for_y * j;
            for (int s = 0; s <= N; s++) {
                z = bounds[2].first + h_for_z * s;

                result += (h_for_x * h_for_y * h_for_z) * f({x, y, z});
            }
        }
    }

    for (int i = 1; i < N; i++) {
        x = bounds[0].first + h_for_x * i;
        for (int s = 1; s < N; s++) {
            z = bounds[2].first + h_for_z * s;

            result += (h_for_y/2) * (f({x, bounds[1].first, z}) +
            f({x, bounds[1].second}, z}));
        }
    }

    for (int j = 1; j < N; i++) {
        y = bounds[1].first + h_for_y * j;
        for (int s = 1; s < N; s++) {
            z = bounds[2].first + h_for_z * s;

            result += (h_for_x/2) * (f({bounds[0].first, y, z}) +
            f({bounds[0].second, y, z}));
        }
    }

    for (int i = 1; i < N; i++) {
        x = bounds[0].first + h_for_x * i;
        for (int j = 1; j < N; j++) {
            y = bounds[1].first + h_for_y * j;

            result += (h_for_z/2) * (f({x, y, bounds[2].first}) +
            f({x, y, bounds[2].second}));
        }
    }

    for (int i = 1; i < N; i++) {
        x = bounds[0].first + h_for_x * i;

        result += (h_for_y/2) * (h_for_z/2) *
        (f({x, bounds[1].first, bounds[2].first}) +
        f({x, bounds[1].second, bounds[2].second}));
    }

    for (int j = 1; j < N; j++) {
        y = bounds[1].first + h_for_y * j;

        result += (h_for_x/2) * (h_for_z/2) *
        (f({bounds[0].first, y, bounds[2].first}) +
        f({bounds[0].second, y, bounds[2].second}));
    }

    for (int s = 1; s < N; s++) {
        z = bounds[2].first + h_for_z * s;

        result += (h_for_y/2) * (h_for_z/2) *
        (f({bounds[0].first, bounds[1].first, z}) +
        f({bounds[0].second, bounds[1].second, z}));
    }

    return result;
}

double trapezoid_method(
    double (*f)(std::vector<double>),
    const std::vector<std::pair<double, double>>& bounds,
    int dimensions,
    int N) {
    if (dimensions != bounds.size()) {
        throw R"(The number of boundaries does not
        match the number of dimensions)";
    }
    if (dimensions == 1) {
        return d1_method(f, bounds, N);
    }
    if (dimensions == 2) {
        return d2_method(f, bounds, N);
    }
    if (dimensions == 3) {
        return d3_method(f, bounds, N);
    }
}
