make
module load anaconda/python3
module load rocks-openmpi-_ib
echo "Parte 1 a):"
mpiexec -v -n 4 hello
echo "Parte 1 b):"
mpiexec -v -n 4 mpisend_recv
echo "Parte 2 c) d) e):"
mpiexec ./sample 1000 0 0.2

python3 graficar.py 1000 0 0.2

