This is a reader of QED data so that it can be processed by the code CRIPTIC.

The read_header.cpp program reads the (matter) density, momentum-density and internal energy from the QED data and then processes it to get the velocity, temperature, kinetic energy and chemical abundances like hydrogen density, relative electron density, relative Helium density, relative H+ density, etc. (here the word 'relative' means per atom of hydrogen).

Since QED is hydrodynamical simulation, the reader assumes a uniform magnetic field of B_0 = 1e-6 G in the vertical (z) direction. This would be modified after the magneto-hydrodynamical simulations are available.
To calculate the chemical abundances, the reader assumes that the number ratio of Helium to Hydrogen is 0.1, and it approximates the adiabatic constant of the gas to 5/3.

To get this code working, follow these steps - 


1. Clone this repo into your local directory of choice- git clone --recursive https://github.com/aditivijayan/CripticReader.git
2. Copy the data into your_dir/CripticReader/data
3. Do - "make". This should create an executable named "reader" in your folder.
4. Run the executable - ./reader
5. The output should be something like-
   Loading data from path: /path_to_folder/data/plt00001
   Loading data from: /path_to_folder/data/plt00001/Level_0/Cell_D_00000
   Data from all_blocks: 2.48635e-30
   Block data: 2.48635e-30
