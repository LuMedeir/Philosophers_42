# Philosophers
<p align="center">
<img src="./philosopherse.png">
</p>

</br>

## Description  
With this project, I learned about concurrency and synchronization in operating systems, and how to deal with issues related to parallel programming and resource sharing in multithreaded environments.

 #### Philosophers challenge
 - The philosophers challenge is a classic concurrency problem in operating systems. It involves a scenario where several philosophers are seated at a round table with food plates between them. There is a shared fork between each pair of adjacent philosophers. To eat, a philosopher needs two forks. However, they can only pick up the forks to their left and right. The challenge is to ensure that the philosophers do not deadlock, where each philosopher has one fork and is waiting for the other. This requires synchronization techniques to prevent conflicts in accessing shared resources (forks) and ensure that all philosophers have the opportunity to eat.

## Makefile rules

| Rule         |                 Description                             |
|:------------:|:-------------------------------------------------------:|
| `make`       | Compile the program.                                    |
| `make clean` | Remove every objects of compilation                     |
| `make fclean`| Do `clean` rule and remove the executable program       |
| `make re`    | Do `fclean` rule and compile the program mandatory      |

## Instalation 
### Clone the repository:
``` 
git clone https://github.com/LuMedeir/Philosophers_42.git
cd ./philosophers/philo
```
### Run Philosophers
```
make
./philo
```
*to execute:*
```
./philo 4 310 200 100 (a philo should die)
./philo 4 410 200 200 (no one should die)
./philo 5 800 200 200 7 (no one should die, simulation should stop after 7 eats)
./philo 5 800 200 200 15 (no one should die, simulation should stop after 15 eats)
```
