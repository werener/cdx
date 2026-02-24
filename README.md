# CDX
CLI tool to create associations between an alias and a particular directory to access it more easily.

## Functionality

Usage: 
```markdown
cdx <command> [OPTIONS] [ARGS]`
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


| **Option**          | **Description**                                            |
| ------------------- | ---------------------------------------------------------- |
| -r,--relative       | Adds exactly path [DIR] to the config, without any changes |
| -g,--generate=TITLE | [TODO]                                                     |

#### **list**
Lists all created associations
Usage: 
```markdown
cdx list [OPTIONS]
```


### TODO list

#### **generate**
Generate bash function TITLE that substitutes for using cdx [ALIAS]
#### **rename** 
Re-assign alias
#### **remove**
Remove an association
