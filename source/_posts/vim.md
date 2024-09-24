# BASIC
## Inserting text  
Press  ` i ` to enter Insert mode.Now behabes like any other text editor,until you press` <ESC> ` to return Normal mode.
## Buffers,tabs,and windows  
Vim maintains a set of open files,called "buffers".Ant time we open an existing file or create a new one using Vim,a buffer will be allocated as the in-memory representation of said file.Any changes we make will be tracked within the buffer.When we are ready to update the file,the buffer can be written to disk. A vim seesion has a number of tabs, each of which has a number of windows. Each windows show a single buffer. Unlike other programs you are familiar with, like web browsers, there is not a 1-to-1 corrsepondence between buffers and windows,even within the same tab,This can be quite handy,for example,to view two deifferent parts of a files at the same time.nt 
## Command-line  
Command mode can be entered by typing` : ` in Normal mode.Your cursor will jump to the command line at the bottom of the screen upon pressing` : `. This mode has many functionities,including openning, saving, and closing files, and quitting Vim.  
* ` :q ` quit
* ` :w ` save
* ` :wq` save and quit
* ` :e{name of file} ` open file for editing
* ` :ls ` show open buffers
* `help {topic} `open help  
    * `help :w` opens help for the ` w `command
    * `help w`opens help for the `w`movement
# Vim's interface is a programming language
The most impritant idea in vim is that **Vim's interface itself** ia a programming language.Ketstrokes(with mnmonic names)are ccommands,and these commands compose.This enables efficient movement and edits,especilly once the commands become muscle memory.
## Movement
The movement that used to navigate the buffer,are also called"nouns", because they refer to chunks of text.
* Basic movement:`hjkl`(left,down,up,right)
* Words:`w`(next word), `b`(beginning of word), `e`(end of word)
* Lines:`0`(beginning of line), `^`(firsy non-blank character),`$` (end of line)
* 
