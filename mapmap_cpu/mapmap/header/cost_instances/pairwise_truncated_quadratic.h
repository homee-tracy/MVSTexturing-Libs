/**
 * Copyright (C) 2017, Daniel Thuerck
 * TU Darmstadt - Graphics, Capture and Massively Parallel Computing
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license. See the LICENSE file for details.
 */

#ifndef __MAPMAP_PAIRWISE_TRUNCATED_QUADRATIC_H_
#define __MAPMAP_PAIRWISE_TRUNCATED_QUADRATIC_H_

#include <mapmap/header/defines.h>
#include <mapmap/header/costs.h>

NS_MAPMAP_BEGIN

template<typename COSTTYPE, uint_t SIMDWIDTH>
class PairwiseTruncatedQuadratic : public PairwiseCosts<COSTTYPE, SIMDWIDTH>
{
public:
    PairwiseTruncatedQuadratic();
    PairwiseTruncatedQuadratic(const _s_t<COSTTYPE, SIMDWIDTH>& c,
        const _s_t<COSTTYPE, SIMDWIDTH>& label_diff_cap);
    PairwiseTruncatedQuadratic(const std::initializer_list<
        _s_t<COSTTYPE, SIMDWIDTH>>& ps);
    ~PairwiseTruncatedQuadratic();

    _s_t<COSTTYPE, SIMDWIDTH> get_label_diff_cap() const;
    _s_t<COSTTYPE, SIMDWIDTH> get_c() const;

    virtual std::unique_ptr<PairwiseCosts<COSTTYPE, SIMDWIDTH>> copy() const;

    virtual bool supports_enumerable_costs() const;
    virtual bool eq(const PairwiseCosts<COSTTYPE, SIMDWIDTH> * costs) const;

    virtual _v_t<COSTTYPE, SIMDWIDTH> get_pairwise_costs(
        const _iv_t<COSTTYPE, SIMDWIDTH>& label_vec_1,
        const _iv_t<COSTTYPE, SIMDWIDTH>& label_vec_2) const;
    virtual _v_t<COSTTYPE, SIMDWIDTH> get_pairwise_costs_enum_offsets(
        const _iv_t<COSTTYPE, SIMDWIDTH>& label_ix_vec_1,
        const _iv_t<COSTTYPE, SIMDWIDTH>& label_ix_vec_2) const;

protected:
    _s_t<COSTTYPE, SIMDWIDTH> m_c = (_s_t<COSTTYPE, SIMDWIDTH>) 1;
    _s_t<COSTTYPE, SIMDWIDTH> m_label_diff_cap = (_s_t<COSTTYPE, SIMDWIDTH>) 9;
};

template<typename COSTTYPE, uint_t SIMDWIDTH>
using PairwiseTruncatedQuadratic_ptr = std::shared_ptr<
    PairwiseTruncatedQuadratic<COSTTYPE, SIMDWIDTH>>;

NS_MAPMAP_END

/* include function implementations */
#include <mapmap/source/cost_instances/pairwise_truncated_quadratic.impl.h>

#endif /* __MAPMAP_PAIRWISE_TRUNCATED_QUADRATIC_H_ */
