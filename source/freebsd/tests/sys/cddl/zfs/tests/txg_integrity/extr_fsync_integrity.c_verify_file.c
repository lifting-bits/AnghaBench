#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  pattern_t ;

/* Variables and functions */
 int NUM_CHUNKS ; 
 scalar_t__ NUM_THREADS ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int,int,...) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  get_chunk_range (int /*<<< orphan*/  const*,int,int*,int*) ; 
 int /*<<< orphan*/ * malloc (size_t) ; 
 int /*<<< orphan*/  marker_fill (int /*<<< orphan*/ *,int,size_t,scalar_t__) ; 
 int /*<<< orphan*/  perror (char*) ; 
 scalar_t__ read (int,int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static int
verify_file(int fd, const pattern_t* p_pat){
  int chunk_idx;
  int good_data = 1;
  int err = 0;

  for(chunk_idx=0; chunk_idx < NUM_CHUNKS; chunk_idx++){
    int i;
    uint32_t chunk_start, chunk_end;
    get_chunk_range(p_pat, chunk_idx, &chunk_start, &chunk_end);
    size_t size =  chunk_end - chunk_start;
    uint64_t* desired_buf = malloc(size);
    uint64_t* actual_buf = malloc(size);
    marker_fill(desired_buf, chunk_start, size, NUM_THREADS - 1);

    //read the actual data from the file
    if( read(fd, actual_buf, size) <= 0 ){
      perror("read");
      exit(1);
    }

    //verify the data
    for(i=0; i < size / sizeof(uint64_t); i++){
      int chunk_offset = sizeof(uint64_t) * i;
      int file_offset = chunk_start + chunk_offset;
      if (good_data && (actual_buf[i] != desired_buf[i])){
        fprintf(stderr, "fsync_integrity: miscompare at "
	    "chunk %i, chunk offset %lx, file offset %lx\n",
	    chunk_idx, chunk_offset, file_offset);
        fprintf(stderr, "Expected %016lx, got %016lx\n",
	    desired_buf[i], actual_buf[i]);
        err = 1;
	good_data = 0;
      }
      else if (!good_data && (actual_buf[i] == desired_buf[i])) {
      	fprintf(stderr, "fsync_integrity: miscompare ends at "
	    "chunk %i, chunk offset %lx, file offset %lx\n",
	    chunk_idx, chunk_offset, file_offset);
	good_data = 1;
      }
    }
    free(desired_buf);
    free(actual_buf);
  }

  return (err);
}