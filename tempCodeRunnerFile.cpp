string Period::toString(){
    char* startInfo = new char[9];
    char* endInfo = new char[9];
    char timeFormat[20] =  "%d,%M,%Y";
    strftime(startInfo,50,timeFormat,&startDate);
    strftime(endInfo,50,timeFormat,&endDate);
    return startInfo;
}