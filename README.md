# AltParser

AltParser is a compare dependencies manager.

## Dependencies for build

You must install this dependencies for build

```
libcurl4-openssl-dev nlohmann-json3-dev
```

## Build 

Change your current directory to root project directory in terminal and run this:

```bash
./build.sh
```
After a successful build, the altparser program will appear in the folder ./Build/Alt/

## Use

### Compare

To compare two branches, you can use:

```
./altparser <branch1> <branch2>
```
For example:
```bash
./altparser p10 p6
```
### Output a comparison to file

If you need to output a comparison to a file, you should add the "-o" key:

```
./altparser <branch1> <branch2> -o <file>
```
For example:
```bash
./altparser p10 p6 -o compare.json
```

### Space indent in output

If you need to add indent space, you should add key "--indent":

```
./altparser <branch1> <branch2> --indent <count>
```
For example:
```bash
./altparser p10 p6 --indent 4
```

### Not download branches

If you need to use cache, you should add key "--cache":

```
./altparser <branch1> <branch2> --cache
```
For example:
```bash
./altparser p10 p6 --cache
```
