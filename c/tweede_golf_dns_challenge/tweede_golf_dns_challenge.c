


uint8_t *unpack_dns(uint8_t *src) {
    char *buf, *dst;
    int len;
    
    buf = dst = malloc(strlen(src) + 1);

    while((len = *src++) != 0) {
        while(len--)
            *dst++ = *src++;
        *dst++ = '.';
    }

    dst[-1] = 0;
    return buf;
}


int DNS_Unpack_Domain_Name(uint8_t *dst, uint8_t *src, uint8_t *buf_begin) {
    int16_t size;
    int     i, retval = 0;
    uint8_t *savesrc;

    savesrc = src;

    while(*src) {
        size = *src;

        while((size & 0xC0) == 0xC0) {
            if(!retval) {
                retval = src - savesrc + 2;
            }

            src++;
            src = &buf_begin[(size & 0x3F) * 256 + *src];       /* ! */
            size = *src;
        }

        src++;

        for(i=0; i < (size & 0x3F); i++) {                      /* ! */
            *dst++ = *src++;
        }

        *dst++ = '.';
    }
    *(--dst) = 0;                                               /* ! */
    src++;

    if(!retval) {
        retval = src - savesrc;
    }

    return retval;
}


int main() {
    return 0;
}

