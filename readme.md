# About this repo
This repo holds ressources for the debugging workshop hosted by 42Tutors on Mon 20.01.2025. 

You will find :
- the slides both in [html](presentation-supports/presentation.html) and [pdf](presentation-supports/presentation.pdf) formats;
- the [code exemples](code-example) shown during the event
- additional documentation such as
	- [a gdb cheatsheet](documentation/gdb-cheatsheet.md)
	- [the sources](documentation/presentations-sources.md) on which we based the presentation
	- the raw [presentation](presentation.md), written in Markdown with [Marp](https://github.com/marp-team/marp-cli) that you can export to .html, .pdf, .pptx and more. To export to a file format, you may use the [generate-presentation.sh](#how-to-use) script.

## How to use generate-presentation.sh
This script is used to generate a usable support file from the .md file. 

If you don't have node, install it:
```bash
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.40.1/install.sh | bash
source ~/.zshrc # or .bashrc, or whatever interpreter you use
nvm install node
nvm use node
```
If you want to export the presentation to .html format, run the script: 
```bash
./generate-presentation.sh
```
Or you can run this command and replace the extension with the one you want:
```bash
npx @marp-team/marp-cli@latest presentation.md --allow-local-files -o presentation-supports/presentation.<html|pdf|pptx> 
```

## Want to contribute ? 
You have read the sources, understood the slides, and you think something is missing ? You're probably right. 

Please don't hesitate to **[contribute](https://docs.github.com/en/get-started/exploring-projects-on-github/contributing-to-a-project)** to the repo, taking care to follow the usual process described in the link. When prompted, please PR to the [Tutor42Lyon repo](https://github.com/Tutors42Lyon/debug-workshop/edit/main/readme.md)

Please keep in mind that this is meant as an _introduction_ to gdb and Valgrind, but have at it if you want to !

# Directory structure
```bash
.
├── assets
│   ├── event_description.md
│   ├── gdb.png
│   ├── gnu_my_beloved.gif
│   ├── tutor.svg
│   └── val.png
├── code-example
│   ├── gdb-demo
│   │   ├── headers
│   │   │   └── RPN.hpp
│   │   ├── Makefile
│   │   └── src
│   │       ├── main.cpp
│   │       └── RPN.cpp
│   └── leak-examples
│       ├── ex
│       └── example.c
├── documentation
│   ├── gdb-cheatsheet.md
│   ├── pdf-doc
│   │   ├── gcc.pdf
│   │   └── GDB Cheat Sheet - GDB Cheat Sheet.pdf
│   └── presentations-sources.md
├── generate-presentation.sh
├── presentation.md
├── presentation-supports
│   ├── presentation.html
│   └── presentation.pdf
└── readme.md

```
# Authors
2025 - [@cdomet-d](https://github.com/cdomet-d) && [@Ofacy](https://github.com/Ofacy)
