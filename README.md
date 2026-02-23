## Functionality

Usage: 
```markdown
cdx <command> [OPTIONS] [ARGS]`
```

| **Option**    | **Description**                     |
| ------------- | ----------------------------------- |
| -v, --version | Show version of current istallation |

## Commands

#### **add**

Usage: 
```markdown
cdx add [ALIAS] [DIR] [OPTIONS]
```
Adds directory DIR (current directory by default) under alias ALIAS (last subdirectory by default)

| **Option**                 | **Description**                                                                   |
| -------------------------- | --------------------------------------------------------------------------------- |
| -f,--force  {TODO}         | No confirmation needed for alias creation                                         |
| -g,--generate=TITLE {TODO} | Immediately generate bash function [TITLE] that substitutes for using cdx [ALIAS] |

#### **list**

Usage: 
```markdown
cdx list [OPTIONS]
```
Lists all created aliases

#### **rename** {TODO}

#### **remove** {TODO}

## ideas

#### **generate**
Generate bash function TITLE that substitutes for using cdx [ALIAS]