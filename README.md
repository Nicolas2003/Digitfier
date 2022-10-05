# Digitfier - Identifying handwritten digits via image recognition

This program was developed with the following libraries:

- [Splashkit](https://github.com/splashkit)
- [libbmp](https://github.com/marc-q/libbmp)
- [Genann](https://github.com/codeplea/genann)
- [Bitmap-Numbers-Dataset](https://github.com/KentoNishi/Bitmap-Numbers-Dataset)

Compile:

```bash
$ skm clang++ main.cpp lib/bitmap/libbmp.cpp image.cpp neural.cpp sample.cpp panel.cpp lib/genann/genann.c -o digitfier
```

Execute:
```bash
$ ./digitfier
```
