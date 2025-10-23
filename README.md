# Very Personal GIT Tool

Just grab the `.c` compile it and use it

![image](https://github.com/user-attachments/assets/50cc89cd-9d35-41c7-9f3d-f44b2749e19c)

## Build
### Prerequisites
To build this tool, you need :
- `git`
- `gcc`
- `make`

### Building
To build the tool, simply execute this command sequence:
```bash
git clone https://github.com/Wateir/VPgitT
cd VPgitT
make
```
#### Arch Linux
Installation
```bash
git clone https://github.com/Wateir/VPgitT && cd VPgitT
makepkg -si --cleanbuild
cd .. && rm -fr VPgitT
```
Uninstall 
```bash
# pacman -R VPgitT-git
```

## Use

`VPgitT commit` basicly git commit  
`VPgitT change` basicly git commit -amend  
`VPgitT checkout [Branch-name]` if given a branch name, make a  `git switch Branch-name`, if not show a fuzzy finder menu to choose which branch switch  

### Configuration

` make MAX_LENGTH=<max commit and description lenght>` If none specified, 256 char is default  

For arch base distro, change this one ligne 24 of `pkgbuild` before make `makepkg -si`
