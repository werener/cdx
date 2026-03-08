# CDX
CLI tool to create associations between an alias and a particular directory to access it more easily.

## Functionality

Usage: 
```markdown
cdx <command> [OPTIONS] [ARGS]
```

| **Option**    | **Description**                              |
| ------------- | -------------------------------------------- |
| -v, --version | Show version of current istallation          |
| --new-config  | Resets configuration of current installation |
### Subcommands

#### **add**

Creates an association between an alias and a directory
Usage: 
```markdown
cdx add [ALIAS] [DIR] [OPTIONS]
```

| **Option**          | **Description**                                   |
| ------------------- | ------------------------------------------------- |
| -r,--relative       | Adds path [DIR] to the config without any changes |
| -g,--generate=TITLE | [TODO]                                            |

#### **list**
Lists all created associations
Usage: 
```markdown
cdx list [OPTIONS]
```

#### **remove**
Removes all associations, listed in [ALIASES]
Usage:
```markdown
cdx remove [ALIASES] [OPTIONS]
```

| **Option**   | **Description**                                      |
| ------------ | ---------------------------------------------------- |
| -a, --all    | Adds all associations to the list of removals [TODO] |
| -e, --except | Ignores this association during removal [TODO]       |
#### **rename** 
Re-assign alias
Usage:
```markdown
cdx rename [ALIAS] [NEWALIAS]
```
#### **generate [TODO]**
Generate bash function TITLE that substitutes for using cdx [ALIAS]
#### **config**
Get information about the configuration file directly
Usage:
```markdown
cdx config [ACTION]
```

| **Option** | **Description**                                      |
| ---------- | ---------------------------------------------------- |
| show       | Adds all associations to the list of removals [TODO] |
| locate     | Gets a path  [TODO]                                  |
| reset      | Completely resets comfiguration [TODO]               |
