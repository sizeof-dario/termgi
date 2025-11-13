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
## The 256 colours set
## The 24-bit colours set
