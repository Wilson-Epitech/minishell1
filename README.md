<div align="center">

# Minishell 1

**Mon premier shell Unix.**

<img alt="C" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white"/> <img alt="Make" src="https://img.shields.io/badge/Make-427819?style=for-the-badge&logo=gnu&logoColor=white"/> <img alt="Unix" src="https://img.shields.io/badge/Unix-333333?style=for-the-badge&logo=linux&logoColor=white"/>

<sub>Projet solo · 2023</sub>

</div>

<br/>

<p align="center"><img src=".github/assets/minishell1.gif" alt="Minishell 1" width="820"/></p>

## En deux mots

Un interpréteur de commandes inspiré de tcsh : un prompt, l'exécution de programmes, et la gestion de l'environnement. La base de tout ce qui a suivi ([Minishell 2](https://github.com/Wilson-Epitech/minishell2), [42sh](https://github.com/Wilson-Epitech/42sh)).

## Ce que ça fait

- Exécution des programmes avec `fork` + `execve`, recherche dans le `PATH`
- Builtins `cd` (avec `~`), `env`, `setenv`, `unsetenv`, `exit`
- Prompt avec l'utilisateur et le dossier courant
- Message d'erreur quand une commande est introuvable

## Sous le capot

Une boucle lit une ligne, la découpe en arguments, vérifie si c'est un builtin, sinon cherche le binaire dans chaque dossier du `PATH`, fork, exécute, puis attend le fils et récupère son code de retour.

## Lancer le projet

```bash
make
./mysh
```
