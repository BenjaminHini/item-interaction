# item-interaction 

This program creates a ***theater*** in wich many differents items interact togethers. you can look at this theater from the **output.svg** or the **index.html** files.

## Interacting with the theater
You have many commands you can user to interact with the theater:
-   exit to clode the program
-   load `<filename>` to load a theatre from a **.rom** file (you have test.rom and fichier.rom available in the repository)
-   reload to reload the theater previously loaded
-   ids/noids to show/hide the names of the different items composing the theater
-   rulers/norulers to show/hide the surface each item can move on
-   store/restore to store the theater at a specific moment and restore it whenever you want (you can only store one theater at a time)
-   save `<filename>` to save the theater in a **.rom** file
-   script `<filename>`to start a script (*modulo.txt* is a  script available in the repository)

##  Interacting with the items

there are 4 interaction you can give to your items:
-   move x moves the selected item to the x% of the field
-   move +/-x increase the selected item's position of +/- x
-   rotate x rotate the selected item of x degre
-   rotate +/-x increase the selected item's rotation of x degre

to select an item you have to @ it, for exemple if you want to advance bot1 of 10 you will do :
```
>@bot1 move +10
```
The @ character also keeps the selected item in memory so you don't have to @ it every time
```
bot1> move -10
```
will move the bot back to its original position


You can also select multiple items at once by using their generic name (without index), for example to rotate every bots to a 30° angle yo do :
```
>@bot rotate 30
```

Finally, you can select different items using the *%*, this will lead to a selection of every items within a condition on their index.
```
>@bot0%2 move 10
```
will select every bots with an index of 0[2] (bot0, bot2, bot4...) and move them. 
