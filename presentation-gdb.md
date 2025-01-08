---
marp: true
theme: uncover
header: Atelier debug
footer: ![width:6em](assets/tutor.svg)

style: |
    section {
        font-family: monospace;
    }
    footer {
        text-align: left;
    }
    section.slide li {
    font-size: 0.7em;
    }
    section.slide h1 {
    font-size: 1em;
    }
---
<!-- _class: slide -->

# 2) Debugger
a. Quand utiliser un debugger?

- Quand on ne comprend pas
- Diagnostiquer des crash
- Diagnostiquer des leaks
- ...

---
<!-- _class: slide -->

# 2) Debugger
b. OK mais c'est quoi?

- Un outil qui permet d'analyser l'execution de son code
- Fini les printf dans tous les sens!

---
<!-- _class: slide -->

# 2) Debugger
c. GDB

- Un debugger basique pour le C/C++
- Utilisable dans le terminal
- Integration avec vos IDE favoris (VS Code, CLion...)
- Pas mal de customisation (debrouillez vous)
- Fonctionne tres bien!

---
<!-- _class: slide -->
# 2) Debugger
d. Les bases (DEMO avec GDB)

- Breakpoints
- Controle de l'execution
- Inspection d'une frame
- Backtrace
