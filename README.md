# Installation du projet
Faites make dans la racine du projet, le Makefile appellera CMake et compilera les sources du projet à partir du Makefile produit.

# Arborescence

- /models<br />
Placez ici les modèles utilisés par le projet sous forme de dossier contenant le nom du modèle

- /plugins<br />
C'est ici que sortent les plugins compilés.

- /project-sources/src/<br />
Contient les sources .cc des plugins du projets

- /project-sources/include/<br />
Contient les headers .hpp utilisé par les plugins du projets

# Modélisation du monde

- make build<br />
Crée le dossier project-build et appelle CMake à l'interieur

- make compile<br />
Compile les sources du projet dans le dossier plugins, instruction par défaut.

- make clean<br />
Efface les plugins compilés dans le dossier plugins.

- make clearall<br />
Efface les plugins et le repertoire projet-build

- make build-clean<br />
Efface le repertoire project-build

# Simulation du robot

- cd ~/catkin_husky/<br />
- catkin_make<br />
- source ~/catkin_husky/devel/setup.bash<br />
- rosrun husky_nav nav<br />
