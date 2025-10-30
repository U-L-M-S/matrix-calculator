# Repository Guidelines

## Project Structure & Module Organization
- Core source lives in `main.cpp` with shared declarations in `main.h`; both sit at the repository root for quick inspection.
- Visual Studio project metadata (`Matrix_Calculator.vcxproj`, `.vcxproj.filters`) drives the Windows build; keep any new source files referenced there.
- Favor grouping future helpers into `src/` and tests into `tests/` if the codebase grows, mirroring the Visual Studio filter layout.

## Build, Test, and Development Commands
- `msbuild Matrix_Calculator.vcxproj /p:Configuration=Debug` builds the interactive console app using MSVC; switch `Debug` to `Release` for optimized output.
- `g++ -std=c++17 main.cpp -o bin/matrix_calculator.exe -static -luser32` works with MinGW; ensure `bin/` exists and run the executable from there.
- Run the program with `bin/matrix_calculator.exe` (or the Visual Studio output) to exercise the menu-driven flows.

## Coding Style & Naming Conventions
- Keep 4-space indentation (no tabs) and brace-on-new-line for functions, matching the existing formatting.
- Prefer lowerCamelCase for functions (`matrixMultiplication`) and descriptive nouns for variables (`rowsMatrixA`).
- Use standard headers over MFC; include `windows.h` only where Sleep or console APIs are required. Document non-portable calls inline.
- Re-run `clang-format -style=Microsoft main.cpp` before committing; add a `.clang-format` if team-wide tweaks are needed.

## Testing Guidelines
- No automated test harness exists yet; add console-driven regression scripts under `tests/` and reference them in the PR when relevant.
- Create reproducible scenarios for matrix operations (multiplication, addition) and capture expected console transcripts in Markdown snippets.
- When adding numerical routines, validate edge cases (non-square matrices, zero rows) manually and describe verification steps in the PR body.

## Commit & Pull Request Guidelines
- Follow concise, imperative commit messages (`Add manual matrix sum walkthrough`), mirroring the existing history.
- Each PR should link related issues, describe functional changes, and note manual test commands executed.
- Provide screenshots or console captures when the output changes, and call out Windows-only dependencies or setup steps for reviewers.
