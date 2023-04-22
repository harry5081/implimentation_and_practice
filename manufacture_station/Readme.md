## Manufacture line instruction.

# executable file: process_line
# record of the process: station_state.txt

1. Start the sw: ./process_line.
2. Choose if you like to restart and reset the process from the last time -> by entering "Y".
	     or continue the process from the last time 		  -> by entering "N".
3. Set the stations in sequence(eg, ABCDCBA).
   Note: D station is not allowed be placed as the first station.
4. Enter the material. It should be an integer.
5. Choose if you want to create another manufacturing line (Y) or the work for today is enough (N).
6. The information of finished products and opteration time of each station will be displayed.
7. Opteration time of each station will be saved as the file "station_state.txt".
8. Feel free to copy the file as a backup, so that you can continue the manufacture process from this time.



## Mantis instruction for developers.

1. To design a new station by yourself: 
  - inheritance the abstract class
  - implement exe(), manufacture(), give_to()

2. After a new type of machine is designed, such as E, the swith cases MMI and storage modules also have to be modified.
   The next development step could be implemented a "station_type_manage" module, so that modules can be more generic.

3. Another TODO is to arrange .cpp .h in object files, and use CMAKE more appropriately, so that the whole project is more developer-friendly.

