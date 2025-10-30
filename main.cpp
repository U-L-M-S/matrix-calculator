#include "main.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

struct Matrix {
    std::size_t rows{};
    std::size_t cols{};
    std::vector<double> elements{};

    Matrix() = default;
    Matrix(std::size_t r, std::size_t c) : rows(r), cols(c), elements(r * c, 0.0) {}

    double& at(std::size_t row, std::size_t col) {
        return elements[row * cols + col];
    }

    double at(std::size_t row, std::size_t col) const {
        return elements[row * cols + col];
    }
};

void resetInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::size_t promptPositiveSize(const std::string& prompt) {
    std::size_t value{};
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value > 0) {
            return value;
        }
        std::cout << "Please enter a positive integer.\n";
        resetInputStream();
    }
}

double promptNumber(const std::string& prompt) {
    double value{};
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        }
        std::cout << "Please enter a valid number.\n";
        resetInputStream();
    }
}

int promptMenuChoice(int min, int max) {
    int value{};
    while (true) {
        std::cout << "Choice: ";
        if (std::cin >> value && value >= min && value <= max) {
            return value;
        }
        std::cout << "Please enter a number between " << min << " and " << max << ".\n";
        resetInputStream();
    }
}

bool askYesNo(const std::string& prompt) {
    std::string answer;
    while (true) {
        std::cout << prompt;
        if (std::cin >> answer) {
            if (answer == "y" || answer == "Y" || answer == "yes" || answer == "YES") {
                return true;
            }
            if (answer == "n" || answer == "N" || answer == "no" || answer == "NO") {
                return false;
            }
        }
        std::cout << "Please respond with y/n.\n";
        resetInputStream();
    }
}

Matrix readMatrix(const std::string& name, std::size_t rows, std::size_t cols) {
    Matrix matrix(rows, cols);
    for (std::size_t row = 0; row < rows; ++row) {
        for (std::size_t col = 0; col < cols; ++col) {
            const std::string prompt =
                name + "[" + std::to_string(row + 1) + "," + std::to_string(col + 1) + "]: ";
            matrix.at(row, col) = promptNumber(prompt);
        }
    }
    return matrix;
}

void printMatrix(const Matrix& matrix, const std::string& title) {
    if (!title.empty()) {
        std::cout << title << '\n';
    }
    std::cout << std::fixed << std::setprecision(2);
    for (std::size_t row = 0; row < matrix.rows; ++row) {
        for (std::size_t col = 0; col < matrix.cols; ++col) {
            std::cout << std::setw(10) << matrix.at(row, col);
        }
        std::cout << '\n';
    }
    std::cout << std::defaultfloat;
}

Matrix addMatrices(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols) {
        throw std::invalid_argument("Matrices must share dimensions for addition.");
    }
    Matrix result(lhs.rows, lhs.cols);
    for (std::size_t row = 0; row < lhs.rows; ++row) {
        for (std::size_t col = 0; col < lhs.cols; ++col) {
            result.at(row, col) = lhs.at(row, col) + rhs.at(row, col);
        }
    }
    return result;
}

Matrix subtractMatrices(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols) {
        throw std::invalid_argument("Matrices must share dimensions for subtraction.");
    }
    Matrix result(lhs.rows, lhs.cols);
    for (std::size_t row = 0; row < lhs.rows; ++row) {
        for (std::size_t col = 0; col < lhs.cols; ++col) {
            result.at(row, col) = lhs.at(row, col) - rhs.at(row, col);
        }
    }
    return result;
}

Matrix multiplyMatrices(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.cols != rhs.rows) {
        throw std::invalid_argument("Columns of Matrix A must equal rows of Matrix B for multiplication.");
    }
    Matrix result(lhs.rows, rhs.cols);
    for (std::size_t row = 0; row < lhs.rows; ++row) {
        for (std::size_t col = 0; col < rhs.cols; ++col) {
            double sum = 0.0;
            for (std::size_t k = 0; k < lhs.cols; ++k) {
                sum += lhs.at(row, k) * rhs.at(k, col);
            }
            result.at(row, col) = sum;
        }
    }
    return result;
}

void showMultiplicationInstructions() {
    std::cout << "\nMatrix multiplication is defined when columns of Matrix A equal rows of Matrix B.\n"
              << "Example: A is 2x3 and B is 3x4. Result will be 2x4.\n\n";
}

void showAdditionInstructions() {
    std::cout << "\nMatrix addition requires both matrices to have identical dimensions.\n"
              << "Example: A and B are both 3x3. Result will also be 3x3.\n\n";
}

void showSubtractionInstructions() {
    std::cout << "\nMatrix subtraction shares the same dimension requirements as addition.\n"
              << "Example: A and B must both be 2x2 to compute A - B.\n\n";
}

void runMultiplicationFlow() {
    if (askYesNo("Show multiplication instructions? (y/n): ")) {
        showMultiplicationInstructions();
    }

    const std::size_t rowsA = promptPositiveSize("Rows for Matrix A: ");
    const std::size_t colsA = promptPositiveSize("Columns for Matrix A: ");
    const std::size_t rowsB = promptPositiveSize("Rows for Matrix B: ");
    const std::size_t colsB = promptPositiveSize("Columns for Matrix B: ");

    if (colsA != rowsB) {
        std::cout << "Cannot multiply: columns of Matrix A must equal rows of Matrix B.\n";
        return;
    }

    std::cout << "\nEnter values for Matrix A:\n";
    Matrix matrixA = readMatrix("A", rowsA, colsA);

    std::cout << "\nEnter values for Matrix B:\n";
    Matrix matrixB = readMatrix("B", rowsB, colsB);

    std::cout << "\nMatrix A:\n";
    printMatrix(matrixA, "");

    std::cout << "\nMatrix B:\n";
    printMatrix(matrixB, "");

    try {
        Matrix result = multiplyMatrices(matrixA, matrixB);
        std::cout << "\nA x B:\n";
        printMatrix(result, "");
    } catch (const std::invalid_argument& error) {
        std::cout << "Error: " << error.what() << '\n';
    }
}

void runAdditionFlow() {
    if (askYesNo("Show addition instructions? (y/n): ")) {
        showAdditionInstructions();
    }

    const std::size_t rows = promptPositiveSize("Rows for matrices A and B: ");
    const std::size_t cols = promptPositiveSize("Columns for matrices A and B: ");

    std::cout << "\nEnter values for Matrix A:\n";
    Matrix matrixA = readMatrix("A", rows, cols);

    std::cout << "\nEnter values for Matrix B:\n";
    Matrix matrixB = readMatrix("B", rows, cols);

    std::cout << "\nMatrix A:\n";
    printMatrix(matrixA, "");

    std::cout << "\nMatrix B:\n";
    printMatrix(matrixB, "");

    try {
        Matrix result = addMatrices(matrixA, matrixB);
        std::cout << "\nA + B:\n";
        printMatrix(result, "");
    } catch (const std::invalid_argument& error) {
        std::cout << "Error: " << error.what() << '\n';
    }
}

void runSubtractionFlow() {
    if (askYesNo("Show subtraction instructions? (y/n): ")) {
        showSubtractionInstructions();
    }

    const std::size_t rows = promptPositiveSize("Rows for matrices A and B: ");
    const std::size_t cols = promptPositiveSize("Columns for matrices A and B: ");

    std::cout << "\nEnter values for Matrix A:\n";
    Matrix matrixA = readMatrix("A", rows, cols);

    std::cout << "\nEnter values for Matrix B:\n";
    Matrix matrixB = readMatrix("B", rows, cols);

    std::cout << "\nMatrix A:\n";
    printMatrix(matrixA, "");

    std::cout << "\nMatrix B:\n";
    printMatrix(matrixB, "");

    try {
        Matrix result = subtractMatrices(matrixA, matrixB);
        std::cout << "\nA - B:\n";
        printMatrix(result, "");
    } catch (const std::invalid_argument& error) {
        std::cout << "Error: " << error.what() << '\n';
    }
}

}  // namespace

void runCalculator() {
    std::cout << "=== Matrix Calculator ===\n";
    bool running = true;
    while (running) {
        std::cout << "\nSelect an operation:\n"
                  << "1) Multiply matrices\n"
                  << "2) Add matrices\n"
                  << "3) Subtract matrices\n"
                  << "4) Exit\n";

        const int choice = promptMenuChoice(1, 4);

        switch (choice) {
            case 1:
                runMultiplicationFlow();
                break;
            case 2:
                runAdditionFlow();
                break;
            case 3:
                runSubtractionFlow();
                break;
            case 4:
            default:
                running = false;
                std::cout << "Goodbye!\n";
                break;
        }
    }
}

int main() {
    runCalculator();
    return 0;
}
