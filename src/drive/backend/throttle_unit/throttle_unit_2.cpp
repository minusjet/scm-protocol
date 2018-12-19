#include "throttle_unit.hpp"

void throttle_unit_2(ST_Queue<unsigned int> *throttle_ratio_queue,
                     ST_Queue<Chip_Read_Req> *chip_read_req_queue,
                     ST_Queue<Chip_Read_Resp> *chip_read_resp_queue,
                     ST_Queue<Chip_Write_Req> *chip_write_req_queue,
                     ST_Queue<Chip_Read_Req> *throttled_chip_read_req_queue,
                     ST_Queue<Chip_Read_Resp> *throttled_chip_read_resp_queue,
                     ST_Queue<Chip_Write_Req> *throttled_chip_write_req_queue) {
  throttle_unit(throttle_ratio_queue, chip_read_req_queue, chip_read_resp_queue,
                chip_write_req_queue, throttled_chip_read_req_queue,
                throttled_chip_read_resp_queue, throttled_chip_write_req_queue);
}
