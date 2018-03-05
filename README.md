# Installation du projet
Construisez le projet avec CMake en appellant make build, compilez ensuite les plugins en appellant make.

# Arborescence

-/models
Placez ici les modèles utilisé par le projet sous forme de dossier contenant le nom du modèle
-/plugins
C'est ici que sortent les plugins compilé.
-/project-sources/src/
Contient les sources .cc des plugins du projets
-/project-sources/include/
Contient les headers .hpp utilisé par les plugins du projets

# Makefile

- make build
Construit le projet et enregistre les dossiers plugins et models dans les variables d'envrionnement du projet.

- make compile
Compile les sources du projet dans le dossier plugins, instruction par défault.

- make clean
Efface les plugins compilé dans le dossier plugins.

- make build-clean
Efface les plugins ainsi et nettoie les fichiers et repertoires généré par CMake.
