# Conception et Implémentation d'un OS Temps Réel Multi-cœurs (Bare Metal)
## 📖 Présentation

Ce projet est une implémentation complète d'un **exécutif et ordonnanceur temps réel non-préemptif**, développé "Bare Metal" (sans système d'exploitation hôte) sur une plateforme **Quad-Cœur ARM Cortex-A53** (Raspberry Pi 3).

L'objectif est de maîtriser les contraintes des systèmes critiques embarqués en gérant directement le matériel, de la cohérence mémoire inter-cœurs jusqu'au déploiement du noyau. Le projet intègre une approche **Model-Based Design** pour la génération de l'ordonnanceur.

---

## 🚀 Fonctionnalités Techniques Clés

### 🧠 Cœur du Système (Kernel & Ordonnancement)
* **Architecture Multi-cœurs :** Exploitation parallèle des 4 cœurs du processeur BCM2837.
* **Ordonnanceur Temps Réel :** Exécutif non-préemptif garantissant le déterminisme temporel.
* **Model-Based Design :** Modélisation des tâches et génération du code de contrôle via le langage synchrone **Heptagon/Esterel**.
* **Gestion Mémoire (MMU) :** Configuration de la traduction d'adresses (VA/PA) et des attributs de mémoire (Device vs Normal Memory).

### ⚡ Synchronisation & Cohérence des Données
* **Primitives Atomiques :** Implémentation manuelle en Assembleur AArch64 des instructions **Store-Release (STLR) / Load-Acquire (LDAR)** pour garantir la cohérence séquentielle en mémoire partagée.
* **Mécanismes Avancés :**
    * Mise en œuvre d'**horloges vectorielles** pour l'ordonnancement distribué.
    * Gestion des verrous (Spinlocks) et barrières mémoire (`DMB`, `DSB`).

### 🛠️ Board Support Package (BSP) & Outillage
* **Bootloader Personnalisé :** Développement du protocole de chargement initial en Assembleur (initialisation des piles EL1/EL2, vecteurs d'interruption).
* **Drivers Périphériques :** Pilotes bas niveau pour l'UART (Mini-UART), les GPIOs et les Timers.
* **Chaîne de Déploiement :** Outil hôte pour charger le kernel en RAM via la liaison série.

---

## 📂 Architecture du Code

Le projet est structuré pour séparer clairement les couches matérielles et logicielles :

```bash
RPI3-Multicore-RTOS/
├── 📂 Bootloader_RPi/   # Firmware d'amorçage (ASM/C)
├── 📂 librpi3/          # BSP : Drivers bas niveau (MMU, UART, GPIO, Vector Tables)
├── 📂 Model_Design/     # Modélisation synchrone (Fichiers .ept Heptagon)
├── 📂 Project_Final/    # Noyau de l'OS (Kernel)
│   ├── 📂 gen-t1042/    # Code généré automatiquement (Ordonnancement)
│   ├── main.c           # Point d'entrée du noyau
│   └── threads/         # Implémentation des tâches par cœur
└── 📂 Tools_Loader/     # Outil de déploiement série (Host PC)
