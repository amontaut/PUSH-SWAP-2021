# PUSH-SWAP-2021
Push-swap graded 86 by my peers on 🎃 Ocotober 31, 2021 🎃 with the norm 3.3.32. Works on bash.

In this repo you will find : 
- FINAL-push-swap : 
  - checker_mac and checker_linux : checkers to check if the list is well sorted in the end
  - srcs, includes, Makefile : source code obviously
- SUBJECT-PUSH-SWAP-en.pdf : the subject in english ☕️ 

How did I do ?
- For 100 numbers or less, I find the median, push what is bellow the median in list B, sort the list B with the lowest possible number of actions, and push back the content of list B in list A. Then I do the same for numbers above the median. 
- For more than 100 numbers, I basically do the same but instead of dividing my list in 2 parts (above and bellow the median), I divide it in 4 parts using quartiles (so bellow quartile 1, between quartile 1 and the median, between the median and quartile 3 and above quartile 3). 

To test my program, run `make`, then :
- `ARG="133 -713 -331 54 -994 -17 -110"; ./push_swap $ARG` to see the instructions on screen
- `ARG="133 -713 -331 54 -994 -17 -110"; ./push_swap $ARG | wc -l` to see how many moves it took
- `ARG="133 -713 -331 54 -994 -17 -110"; ./push_swap $ARG | ./checker_mac $ARG` to see if it's well sorted (on macos)
- `ARG="133 -713 -331 54 -994 -17 -110"; ./push_swap $ARG | ./checker_linux $ARG` to see if it's well sorted (on linux)

Of course you can put whatever ints you like in the argument ARG

Here are some ressources I used : 
- Random number generator : https://tinyurl.com/55b82sty

Happy Halloween 👻 

![GitHub repo size](https://img.shields.io/github/repo-size/amontaut/PUSH-SWAP-2021?style=for-the-badge)
