# AGENTS

Guide rapide pour travailler sur `Imagenex852`.

## Objectif du dépôt

Toolkit C++ pour fichiers/sonar Imagenex 852 (CLI + outils exemples, plus GUI/installer via scripts spécifiques).

## Commandes utiles

- `make` : compile les binaires CLI (`dump852`, `octave-dumper`)
- `make coverage` : génère le rapport `cppcheck` XML dans `build/coverage/reports/cppcheck.xml`
- `make clean` : nettoie `build/`

## CI

- CI GitHub Actions: `.github/workflows/ci.yml`
- La CI GitHub couvre:
  - build Linux
  - build Windows CLI
  - rapport `cppcheck`
- Les étapes Jenkins historiques non portables (signature AutoIt, Qt IFW, packaging Windows GUI complet) ne sont pas exécutées par défaut dans GitHub Actions.

## Prérequis locaux (pour packaging avancé)

- Linux GUI/installer: `qmake`, `7z`, Qt Installer Framework (`binarycreator`)
- Windows GUI/installer: Qt MSVC, `jom`, `windeployqt`, 7-Zip, AutoIt, certificats/signature

## Conventions

- Conserver la compatibilité `C++11` (voir `Makefile`)
- Éviter de modifier les scripts `Scripts/*.bat`/`Scripts/*.sh` sans tester sur la plateforme concernée
- Préférer des changements ciblés sur les binaires CLI si l'objectif est la CI multiplateforme
