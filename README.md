# Installation du projet
Faites make dans la racine du projet, le Makefile appellera CMake et compilera les sources du projet à partir du Makefile produit.

# Arborescence

- /models
Placez ici les modèles utilisé par le projet sous forme de dossier contenant le nom du modèle

- /plugins
C'est ici que sortent les plugins compilé.

- /project-sources/src/
Contient les sources .cc des plugins du projets

- /project-sources/include/
Contient les headers .hpp utilisé par les plugins du projets

# Makefile

- make build
Crée le dossier project-build et appelle CMake à l'interieur

- make compile
Compile les sources du projet dans le dossier plugins, instruction par défaut.

- make clean
Efface les plugins compilé dans le dossier plugins.

- make clearall
Efface les plugins et le repertoire projet-build

- make build-clean
Efface le repertoire project-build
