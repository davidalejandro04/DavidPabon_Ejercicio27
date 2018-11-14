module load rocks-openmpi-_ib
echo "Parte 1:"
mpiexec -v -n 4 hello
echo "Parte2:"
mpiexec -v -n 4 mpisend_recv
echo ""
