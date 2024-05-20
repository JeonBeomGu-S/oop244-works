#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_
namespace seneca {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
   bool read(const char* name);
   bool read(int* empNo);
   bool read(double* salary);

}
#endif // !SENECA_FILE_H_
