# TermGI
<div align = "center">
  
**Term**inal **G**raphics **I**nterface
</div>

This library provides a series of tools to help you with the graphics of your terminal applications.

## Major funcions
Although you shuld check code documentation for all the functions this library introduces, the major ones are also discussed in this last section.

### The printfc function
Write formatted and coloured output to stdout.
#### FUNCTION SIGNATURE
```
int printf(const char* const format_and_colour, ...);
```
#### PARAMETERS
1. `format_and_colour`: a string possibily containing format specifiers and colour specifiers to format and colour the output accordingly;
2. `...`: a variadic list of arguments consisting in all the colour values <ins>first</ins> and all the format arguments <ins>then</ins>.
#### RETURN
The number of character written, <ins>excluding</ins> the colour escape sequences.
#### USAGE
Consider this function as an extension of `printf`. You can still use format specifiers `%` in almost the same way as in `printf`. However, `printfc` also allows you to use colour specifiers `#`.
THe following table illustrates how they can be used:
<div align = "center">
        
| char after `#` | Result                                                      |
| :---:          | :---                                                        |
| `f`/`F`        | The corresponding colour is applied to the foreground layer |
| `b`/`B`        | The corresponding colour is applied to the background layer |
| `#`            | It's substituted by a `#`                                   |
| anything else  | It's substituted by a `#` (don't do it on purpose tho)      |
</div>

When passing the variadic arguments, you first need to list all the colours values (that is, their integer rappresentation in the RGB model) then you list all the format arguments.

> Note: SInce `#` can be used <ins>with</ins> format specifiers, you'll need to use a `##` in those cases for the same result.
#### EXAMPLES
```
// Example 1 (printfc works the same as printf on compatible arguments)
int main()
{
        int written1, written2;

        written1 = printf("%s World%c\n", "Hello", '!');
        written2 = printfc("%s World%c\n", "Hello", '!');
        printf("written1 = %d\nwritten2 = %d\n", written1, written2);
}
```
produces the following output:
<div align = "center">
 
![](.assets/example1.png)
</div>

```
// Example 2 (Using colour specifiers)
int main()
{
        printfc("#b#fHello #fWorld#f!\n", 0xFFFFFF, 0x00FF00, 0x0000FF, 0x000000);
}
```
produces the following output:
<div align = "center">
 
![](.assets/example2.png)
</div>

```
// Example 3 (Using colour specifiers TOGETHER WITH format specifiers)
int main()
{
        printfc("#b#%s #fWorld#f%c\n",
                RGB(255, 255, 255), RGB(0, 255, 0), RGB(0, 0, 255), RGB(0, 0, 0),
                "Hello", '!');
}
```
produces the following output:
<div align = "center">
 
![](.assets/example3.png)
</div>

```
// Example 4 (Using # in format specifiers)
int main()
{
        printf("An exadecimal number: %#x\n, 15);
        printfc("An exadecimal number: %##x\n, 15);
}
```
produces the following output:

<div align = "center">
 
![](.assets/example4.png)
</div>