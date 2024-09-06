#ifndef __BITSTRUCT_H__
#define __BITSTRUCT_H__

#include "zfp/internal/zfp/types.h"

/* bit stream word/buffer type; granularity of stream I/O operations */
#ifdef BIT_STREAM_WORD_TYPE
  /* may be 8-, 16-, 32-, or 64-bit unsigned integer type */
  typedef BIT_STREAM_WORD_TYPE bitstream_word;
#else
  /* use maximum word size by default for highest speed */
  typedef uint64 bitstream_word;
#endif

/* number of bits in a buffered word */
#define wsize ((bitstream_count)(sizeof(bitstream_word) * CHAR_BIT))

// bit stream structure  

struct bitstream {
  bitstream_count bits;   /* number of buffered bits (0 <= bits < wsize) */
  bitstream_word  buffer; /* buffer for incoming/outgoing bits (buffer < 2^bits) */
  bitstream_word* ptr;   /* pointer to next word to be read/written */
  bitstream_word* begin; /* beginning of stream */
  bitstream_word* end;   /* end of stream (currently unused) */
#ifdef BIT_STREAM_STRIDED
  size_t mask;     /* one less the block size in number of words */
  ptrdiff_t delta; /* number of words between consecutive blocks */
#endif
};


#endif 
