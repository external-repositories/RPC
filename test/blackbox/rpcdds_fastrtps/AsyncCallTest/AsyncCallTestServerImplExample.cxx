/** 
 * Generated by FASTRPC                                              *
 * Empty interface implementation to be filled with your own code.  *
 */
 
#include "AsyncCallTestServerImplExample.h"

int32_t AsyncCallTestServerImplExample::getLong(/*in*/ int32_t lo1, /*inout*/ int32_t& lo2, /*out*/ int32_t& lo3) 
{
    int32_t  getLong_ret = 0;    

    lo3 = lo2;
    getLong_ret = lo1;
    lo2 = lo1 + lo2;
   
    return getLong_ret;
} 
 
bool AsyncCallTestServerImplExample::getBoolean(/*in*/ bool bo1, /*inout*/ bool& bo2, /*out*/ bool& bo3) 
{
    bool  getBoolean_ret = false;    

    bo3 = bo2;
    getBoolean_ret = bo1;
    bo2 = bo1 | bo2;
   
    return getBoolean_ret;
} 
 
std::string AsyncCallTestServerImplExample::getString(/*in*/ const std::string& s1, /*inout*/ std::string& s2, /*out*/ std::string& s3) 
{
    std::string  getString_ret;    

    s3 = s2;
    getString_ret = s1;
    s2 = s1 + s3;
   
    return getString_ret;
} 
 
Structure AsyncCallTestServerImplExample::duplicate(/*in*/ const Structure& ev) 
{
    Structure duplicate_ret;
        
	duplicate_ret = ev;
   
    return duplicate_ret;
} 
