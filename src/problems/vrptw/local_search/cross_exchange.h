#ifndef VRPTW_CROSS_EXCHANGE_H
#define VRPTW_CROSS_EXCHANGE_H

/*

This file is part of VROOM.

Copyright (c) 2015-2018, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include "problems/cvrp/local_search/cross_exchange.h"
#include "structures/vroom/tw_route.h"

class vrptw_cross_exchange : public cvrp_cross_exchange {
private:
  tw_route& _tw_s_route;
  tw_route& _tw_t_route;

  bool _s_is_normal_valid;
  bool _s_is_reverse_valid;
  bool _t_is_normal_valid;
  bool _t_is_reverse_valid;

  virtual void compute_gain() override;

public:
  vrptw_cross_exchange(const input& input,
                       const solution_state& sol_state,
                       tw_route& tw_s_route,
                       index_t s_vehicle,
                       index_t s_rank,
                       tw_route& tw_t_route,
                       index_t t_vehicle,
                       index_t t_rank);

  virtual bool is_valid() override;

  virtual void apply() override;
};

#endif
