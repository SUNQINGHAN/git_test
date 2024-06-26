double LineSegment2d::DistanceTo(const Vec2d &point) const{
    if(length_ < kMathEpsilon){
        return point.DistanceTo(start_);
    }
    const double x0 = point.x() - start_.x();
    const double y0 = point.y() - start_.y();
    const double proj = x0 * unit_direction_.x() + y0 * unit_direction_.y();
    if(proj <= 0){
        return hypot(x0, y0);
    }
    if(proj >= length_){
        return point.DistanceTo(end_);
    }
    return std::abs(x0 * unit_direction_.y() - y0 * unit_direction_.x());
}