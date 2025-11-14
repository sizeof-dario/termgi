# Colour

One of the first major feature of this library is the possibility to change the colours of text and its background in a terminal.

This README will go through what you need to know about using colours in terminals and, for its last section, about how you can directly play with it
using this library functions. Consider tho that those really are _base_ functions so, for more complex stuff, there may be other functions in this
library that could do the job for you!

First of all, here's a:

> **Not mandatory read, but if you're into jargons:** colours do not belong to the characters displayed themselves.
> There's not such thing as a "_blue 'a' character_" or a "_'b'-with-red-background chraracter_".
> Everything concerning the appereance of text, therefore colours as well, is handled by the terminal
> and it's more of a "graphical artifice" played by the latter.
>
> This means that, technically, you can't write code to "print a green 'c'". You should first have to set the foreground colour (that is, the colour of the text)
> to green, and then go with a `printf("c");`. However, both for simplicity and because this is not relevant for a correct usage of the library functions,
> in the rest of this repository I address colours as a property of characters and I might say things like "_printing a yellow 'd' with a magenta background_".

## Colour sets

There are four sets of colours that are not equally supported by all terminals, each one being a superset of the previous one:

<div align = "center">
 
| Colour set         | Other names            | Supported on [^1]                                    | <ins>Not</ins> supported on [^1] |
| :---               | :---                   | :---                                                 | :---                             |
| **8 colours**      |                        | TTY Linux, GNOME Terminal, Windows Terminal          |                                  |
| **16 colours**     | 8–16 colours           | TTY Linux (<ins>partially</ins>[^2]), GNOME Terminal |                                  |
| **256 colours**    | 8-bit colours          | GNOME Terminal, Windows Terminal                     | TTY Linux                        |
| **24-bit colours** | Truecolor, RGB colours | GNOME Terminal, Windows Terminal                     | TTY Linux                        |

</div>

[^1]: These are just **some** examples, obtained via **personal** testing, so they could be inaccurate and they're not exhaustive at all.
[^2]: Only for foreground colours.

<ins>If you try to use a colour on a terminal that doesn't support it</ins>, nothing bad will happen anyway, <ins>it will</ins> just 
<ins>get approximated by its closest supported colour</ins>.

The following subsections will discuss the abovementioned sets. If you are interested in the details behind the implementation, know that
the _change-colour-commands_ are implemented via [ANSI escape sequences](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797).

### The 8 colours set

This set allows you to use, both for foreground and background:
* Black
* Red
* Green
* Yellow
* Blue
* Magenta
* Cyan
* White

However, there is a:
> **Very <ins>important</ins> thing to know:** these colours are <ins>not</ins> absolute.
> That is, they do not correspond to the same colours for all terminals. Rather, every terminal uses usually slightly – yet different – implementations.

For example, the following table shows their appereance in the terminals I could run tests with:

<div align = "center">

| Colour    | TTY Linux | GNOME Terminal | Windows Terminal | VS Code terminal[^3] |
| :---      | :---:     | :---:          | :---:            | :---:                         |
|**Black**  |![](https://placehold.co/60x15/010101/010101.png)|![](https://placehold.co/60x15/171421/171421.png)|![](https://placehold.co/60x15/0C0C0C/0C0C0C.png)|![](https://placehold.co/60x15/000000/000000.png)|
|**Red**    |![](https://placehold.co/60x15/DE382B/DE382B.png)|![](https://placehold.co/60x15/C01C28/C01C28.png)|![](https://placehold.co/60x15/C50F1F/C50F1F.png)|![](https://placehold.co/60x15/CD3131/CD3131.png)|
|**Green**  |![](https://placehold.co/60x15/39B54A/39B54A.png)|![](https://placehold.co/60x15/26A269/26A269.png)|![](https://placehold.co/60x15/13A10E/13A10E.png)|![](https://placehold.co/60x15/0DBC79/0DBC79.png)|
|**Yellow** |![](https://placehold.co/60x15/FFC706/FFC706.png)|![](https://placehold.co/60x15/A2734C/A2734C.png)|![](https://placehold.co/60x15/C19C00/C19C00.png)|![](https://placehold.co/60x15/E5E510/E5E510.png)|
|**Blue**   |![](https://placehold.co/60x15/006FB8/006FB8.png)|![](https://placehold.co/60x15/12488B/12488B.png)|![](https://placehold.co/60x15/0037DA/0037DA.png)|![](https://placehold.co/60x15/2472C8/2472C8.png)|
|**Magenta**|![](https://placehold.co/60x15/762671/762671.png)|![](https://placehold.co/60x15/A347BA/A347BA.png)|![](https://placehold.co/60x15/881798/881798.png)|![](https://placehold.co/60x15/BC3FBC/BC3FBC.png)|
|**Cyan**   |![](https://placehold.co/60x15/2CB5E9/2CB5E9.png)|![](https://placehold.co/60x15/2AA1B3/2AA1B3.png)|![](https://placehold.co/60x15/3A96DD/3A96DD.png)|![](https://placehold.co/60x15/11A8CD/11A8CD.png)|
|**White**  |![](https://placehold.co/60x15/CCCCCC/CCCCCC.png)|![](https://placehold.co/60x15/D0CFCC/D0CFCC.png)|![](https://placehold.co/60x15/CCCCCC/CCCCCC.png)|![](https://placehold.co/60x15/E5E5E5/E5E5E5.png)|
</div>

As you can see, the difference between terminals (also considering editor/IDEs' ones) is relatively visible, especially with certain colours like yellow, so keep that in mind when designing your applications!

Before moving to the **16 colours set**, this is how this set colours appear when used in the TTY Linux:

<div align = "center">
 
![](.assets/colour-8-tty.png)
</div>

[^3]: With the **Dark+** theme.

### The 16 colours set

This set expands the **8 colours** one with 8 new colours that are the bright versions of the already existing ones, both for the foreground and the background of text.

These colours are <ins>still relative</ins> to the terminal. THey are listed below in the table, shown as how they appear in the GNOME Terminal:
<div align = "center">
 
| Colour    | Swatch                                          |RGB value      |HEX value| Colour           | Swatch                                          |RGB value      |HEX value|
| :---      | :---:                                           | :---:         | :---:   | :---             | :---:                                           | :---:         |:---:    |
|**Black**  |![](https://placehold.co/60x15/171421/171421.png)|` 23,  20,  33`|`#171421`|**Bright black**  |![](https://placehold.co/60x15/5E5C64/5E5C64.png)|` 94,  92, 100`|`#5E5C64`|
|**Red**    |![](https://placehold.co/60x15/C01C28/C01C28.png)|`192,  28,  40`|`#C01C28`|**Bright red**    |![](https://placehold.co/60x15/F66151/F66151.png)|`246,  97,  81`|`#F66151`|
|**Green**  |![](https://placehold.co/60x15/26A269/26A269.png)|` 38, 162, 105`|`#26A269`|**Bright green**  |![](https://placehold.co/60x15/33DA7A/33DA7A.png)|` 51, 218, 122`|`#33DA7A`|
|**Yellow** |![](https://placehold.co/60x15/A2734C/A2734C.png)|`162, 115,  76`|`#A2734C`|**Bright yellow** |![](https://placehold.co/60x15/E9AD0C/E9AD0C.png)|`233, 173,  12`|`#E9AD0C`|
|**Blue**   |![](https://placehold.co/60x15/12488B/12488B.png)|` 18,  72, 139`|`#12488B`|**Bright blue**   |![](https://placehold.co/60x15/2A7BDE/2A7BDE.png)|` 42, 123, 222`|`#2A7BDE`|
|**Magenta**|![](https://placehold.co/60x15/A347BA/A347BA.png)|`163,  71, 186`|`#A347BA`|**Bright magenta**|![](https://placehold.co/60x15/C061CB/C061CB.png)|`192,  97, 203`|`#C061CB`|
|**Cyan**   |![](https://placehold.co/60x15/2AA1B3/2AA1B3.png)|` 42, 161, 179`|`#2AA1B3`|**Bright cyan**   |![](https://placehold.co/60x15/33C7DE/33C7DE.png)|` 51, 199, 222`|`#33C7DE`|
|**White**  |![](https://placehold.co/60x15/D0CFCC/D0CFCC.png)|`208, 207, 204`|`#D0CFCC`|**Bright white**  |![](https://placehold.co/60x15/FFFFFF/FFFFFF.png)|`255, 255, 255`|`#FFFFFF`|
</div>

As you can see, the first 8 colours match – and are in fact the same – the second column of the table in the **8 colours set** section.
Also, this is how they look when used in the GNOME Terminal:
<div align = "center">
 
![](.assets/16-colour-set.png)
</div>

### The 256 colours set
### The 24-bit colours set

## Library colour functions














