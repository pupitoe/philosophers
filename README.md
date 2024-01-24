# philosophers

    -fsanitize=thread
    valgrind --tool=helgrind ./programme.
    valgrind --tool=drd ./programme.

pas oublier que les philosoph commence a 1

faire le 1 philo
regler les probleme avec les mutex lock
gerer le print avec un mutex pour les avoirs dans le bonne ordre (c'est surtout pour que le message de mort soit le dernier)