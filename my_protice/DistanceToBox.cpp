double BBox2d::DistanceTo(const Ved2d &point) const {
    const double x0 = point.x();
    const double y0 = point.y();
    const double dx = x0 * heading_cos + y0 * heading_sin - half_length;
    const double dy = -x0 * heading_sin + y0 * heading_cos - half_length;
    if(dx <= 0){
        return max(0.0, dy);
    }
    if(dy <= 0){
        return dx;
    }
    return hypot(dx, dy);
}