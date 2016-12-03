// Copyright (c) 2016 Doyub Kim

#ifndef INCLUDE_JET_POINT_SIMPLE_LIST_SEARCHER2_H_
#define INCLUDE_JET_POINT_SIMPLE_LIST_SEARCHER2_H_

#include <jet/point_neighbor_searcher2.h>
#include <vector>

namespace jet {

//!
//! \brief Simple ad-hoc 2-D point searcher.
//!
//! This class implements 2-D point searcher simply by looking up every point in
//! the list. Thus, this class is not ideal for searches involing large number
//! of points, but only for small set of items.
//!
class PointSimpleListSearcher2 final : public PointNeighborSearcher2 {
 public:
    //! Default constructor.
    PointSimpleListSearcher2();

    //!
    //! \brief      Builds internal structure for given points list.
    //!
    //! For this class, this function simply copies the given point list to the
    //! internal list.
    //!
    //! \param[in]  points The points to search.
    //!
    void build(const ConstArrayAccessor1<Vector2D>& points) override;

    //!
    //! Invokes the callback function for each nearby point around the origin
    //! within given radius.
    //!
    //! \param[in]  origin   The origin position.
    //! \param[in]  radius   The search radius.
    //! \param[in]  callback The callback function.
    //!
    void forEachNearbyPoint(
        const Vector2D& origin,
        double radius,
        const ForEachNearbyPointFunc& callback) const override;

    //!
    //! Returns true if there are any nearby points for given origin within
    //! radius.
    //!
    //! \param[in]  origin The origin.
    //! \param[in]  radius The radius.
    //!
    //! \return     True if has nearby point, false otherwise.
    //!
    bool hasNearbyPoint(
        const Vector2D& origin, double radius) const override;

 private:
    std::vector<Vector2D> _points;
};

}  // namespace jet

#endif  // INCLUDE_JET_POINT_SIMPLE_LIST_SEARCHER2_H_