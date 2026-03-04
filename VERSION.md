# VERSION

## Schéma de version

- Format: `MAJOR.MINOR.PATCH`
- Base actuelle: `0.1`
- En CI GitHub, `PATCH` est dérivé de `github.run_number`

## Exemple

- Build GitHub Actions n°42 -> `0.1.42`

## Version locale par défaut

- `0.1.0` (référence de travail)

## Recent Changes (English)

- Added `AGENTS.md` with repository usage notes, CI scope, and local build prerequisites.
- Added GitHub Actions CI workflow (`.github/workflows/ci.yml`) to replace the Jenkins pipeline for portable jobs:
  - Linux CLI build
  - Windows CLI build
  - `cppcheck` report artifact upload
- Kept Jenkins-specific signing/installer packaging steps out of the default GitHub CI (Qt IFW, AutoIt, code signing), documented as a separate migration task.
- Fixed a Linux/CI compilation issue by adding `#include <cstdint>` in `src/Imagenex852.hpp` for `uint8_t`/`uint16_t` types.
