# Projet PA 2020

## Objectifs
Mise en application des concepts vus en algorithmique / programmation cette année pour traiter les mesures de pollution fournies par un ensemble de capteurs connectés.

## Auteurs
Kevin Doolaeghe

God-Belange Aradukunda

## Contenu du dépôt

- `README.md` le fichier que vous être en train de lire
- `Makefile` permet la compilation du code à l'aide de la commande `make`
- `.clang-format` contient les règles de formatage de code
- `.gitlab-ci.yaml` contient la description du _pipeline_ d'intégration continue
- le répertoire `includes` contient les déclarations de fonctions
- le répertoire `src` contient les sources du projet

### Configuration

Avant de lancer la compilation, il faut s'assurer que la machine ait les dépendances et paquets requis. Les commandes suivantes permettent d'avoir tout ce qui est nécessaire à l'utilisation du programme

```
apt-get update -y
apt-get upgrade -y
apt-get install -y clang-format clang-tidy clang-tools clang make check cppcheck libcppunit-subunit-dev lcov llvm
```

### Utilisation

Pour utiliser le programme, il faut se placer à la racine du projet et lancer la compilation du programme avec la commande `make`.

Pour essayer correctement le projet, il faut copier le fichier exécutable `project`, situé dans le dossier `build/` dans un dossier d'exécution au choix.

Il peut aussi être créé un fichier de commande dont le nom est libre permettant de faire fonctionner en mode *batch* le programme.

Enfin, il faut déplacer les fichiers de données des capteurs (nom de la forme `pollutionDataXXXXX.csv` où `XXXXX` est un numéro) dans ce même dossier.

Un exemplaire de chacun de ces fichiers se trouve dans le dossier `resources/` du projet.

Pour lancer, le programme, il faut exécuter la commande suivante (se placer dans le dossier d'exécution) :

```
./project .
./project . <fichier de commande>
```
