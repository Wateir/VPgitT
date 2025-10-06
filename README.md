# Very Personal GIT Tool

Just grab the `.c` compile it and use it

![image](https://github.com/user-attachments/assets/50cc89cd-9d35-41c7-9f3d-f44b2749e19c)

## Installation

### Arch Base Distro
```
git clone git@github.com:Wateir/VPgitT.git
cd VPgitT
makepkg -si
```


### Manual install
```
git clone git@github.com:Wateir/VPgitT.git
cd VPgitT
make
```

## Use

`VPgitT commit` basicly git commit  
`VPgitT change` basicly git commit -amend  
`VPgitT checkout [Branch-name]` if given a branch name, make a  `git switch Branch-name`, if not show a fuzzy finder menu to choose which branch switch  

### Dependencies
 `fzf`  
 `git`  

### Configuration

` make MAX_LENGTH=<max commit and description lenght>` If none specified, 256 char is default  

For arch base distro, change this one ligne 24 of `pkgbuild` before make `makepkg -si`
