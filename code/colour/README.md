# Colour handling

One of the first major feature of this library is the possibility to change the colours of text and its background in a terminal.

> **Not a mandatory read, but if you're into jargons:** Colours do not belong to the characters displayed themselves.
> There's not such thing as a "_blue `'a'` character_" or a "_`'b'`-with-red-background chraracter_".
> Everything concerning the appereance of text, therefore colours as well, is handled by the terminal
> and it's more of a "graphical artifice" played by the latter.
>
> This means that, technically, you can't write code to "print a green `'c'`". You should first have to set the foreground colour (that is, the colour of the text)
> to green, and then go with a `printf("c");`. However, both for simplicity and because this is not relevant for a correct usage of the library functions,
> in the rest of this repository I address colours as a property of characters and I might say things like "_printing a yellow `'d'` with a magenta background_".

There are three major[^1] sets of colours that are not equally supported by all terminals, each one being a superset of the previous one:

<div align = "center">
 
| Colour set         | Other names            | Supported on [^2]                          | <ins>Not</ins> supported on [^2][^3] |
| :---               | :---                   | :---                                       | :---                                 |
| **16 colours**     | 8–16 colours           | TTY Linux, GNOME Terminal, VSCode terminal |                                      |
| **256 colours**    | 8-bit colours          | GNOME Terminal, VSCode terminal            | TTY Linux                            |
| **24-bit colours** | Truecolor, RGB colours | GNOME Terminal, VSCode terminal            | TTY Linux                            |

</div>

[^1]: To be precise, there are four such sets. Looking at the table that follows the line referencing this note, you can see the first entry, **16 colours**,
is also known as **8–16 colours**. This is because it is a superset of **8 colours** which is, in some cases, the biggest set of colours really supported on certain terminals.
However, such scenario seems to be pretty rare, only occurring on old phisical terminal or in minimal/embedded systems, so I didn't take it into account.
[^2]: These are just **some** examples, obtained via **personal** testing, so they could be inaccurate and they're not exhaustive at all.
[^3]: Trying to use a colour from an unsupported set results in it getting approximated to its closest match in the biggest supported set.

The following sections will discuss the three abovementioned colour sets. If you are interested in the details behind the implementation, know that
the _change-colour-commands_ are implemented via [ANSI escape sequences](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797).

## The 16 colours set

This set of colours is the most widely supported set. It includes 8 colours with their bright counterparts for a total of 16 (whence the name),
both for the foreground and the background of text.

The only possible downside is that these colours are not absolute.
That means, they do not correspond to the same colours for all terminals. Rather, every terminal uses usually slightly – yet different – implementations.

The colours are still listed and shown in the table below. As for _which_ implementation is used as a reference for the swatches and the RGB and HEX values,
I picked the GNOME Terminal one:

<div align = "center">  

| Colour    | Swatch                                          |RGB value      |HEX value | Colour           | Swatch                                          |RGB value      |HEX value |
| :---      | :---:                                           | :---:         | :---:    | :---             | :---:                                           | :---:         |:---:     |
|**Black**  |![](https://placehold.co/60x10/010101/010101.png)|`  1,   1,   1`|`0x010101`|**Bright black**  |![](https://placehold.co/60x10/808080/808080.png)|`128, 128, 128`|`0x808080`|
|**Red**    |![](https://placehold.co/60x10/DE382B/DE382B.png)|`222,  56,  43`|`0xDE382B`|**Bright red**    |![](https://placehold.co/60x10/FF0000/FF0000.png)|`255,   0,   0`|`0xFF0000`|
|**Green**  |![](https://placehold.co/60x10/39B54A/39B54A.png)|` 57, 181,  74`|`0x39B54A`|**Bright green**  |![](https://placehold.co/60x10/00FF00/00FF00.png)|`  0, 255,   0`|`0x00FF00`|
|**Yellow** |![](https://placehold.co/60x10/FFC706/FFC706.png)|`255, 199,   6`|`0xFFC706`|**Bright yellow** |![](https://placehold.co/60x10/FFFF00/FFFF00.png)|`255, 255,   0`|`0xFFFF00`|
|**Blue**   |![](https://placehold.co/60x10/006FB8/006FB8.png)|`  0, 111, 184`|`0x006FB8`|**Bright blue**   |![](https://placehold.co/60x10/0000FF/0000FF.png)|`  0,   0, 255`|`0x0000FF`|
|**Magenta**|![](https://placehold.co/60x10/762671/762671.png)|`118,  38, 113`|`0x762671`|**Bright magenta**|![](https://placehold.co/60x10/FF00FF/FF00FF.png)|`255,   0, 255`|`0xFF00FF`|
|**Cyan**   |![](https://placehold.co/60x10/2CB5E9/2CB5E9.png)|` 44, 181, 233`|`0x2CB5E9`|**Bright cyan**   |![](https://placehold.co/60x10/00FFFF/00FFFF.png)|`  0, 255, 255`|`0x00FFFF`|
|**White**  |![](https://placehold.co/60x10/CCCCCC/CCCCCC.png)|`204, 204, 204`|`0xCCCCCC`|**Bright white**  |![](https://placehold.co/60x10/FFFFFF/FFFFFF.png)|`255, 255, 255`|`0xFFFFFF`|

</div>

## The 256 colours set
## The 24-bit colours set


