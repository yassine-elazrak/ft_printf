float binaryToFloat(  )
{   
    if( exp == 0 && mantissa == 0 ) {
 
       
       return 0;
 
    } else if( exp == 255 && mantissa == 0 ) {
 
       
        return 0;
 
    } else if( exp == 255 && mantissa != 0 ) {
 
           return 0;
 
    } else if( exp == 0 && mantissa != 0 ) {
 
    
        exp = -126;
 
    } else {
 
  
        exp = exp - 127;
 
     
        mantissa = mantissa | 0x800000;
    }
 
 
    for( i = 0; i > -24; i-- ) {
 
      
        if( mantissa & ( 1 << ( i + 23 ) ) ) {
 
            floatValue += ( float )pow( 2, i + exp );
        }
    }

 ////   return ( sign == FALSE ) ? floatValue : -floatValue;
}
 

int main( void )
{
    printf( "%f\n", binaryToFloat( 0x40B80000 ) );
    return 0;
}