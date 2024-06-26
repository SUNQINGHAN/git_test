bool AABox2d::IsPointIn(const Vec2d &point) const{
    return std::abs(point.x() - center_.x()) <= half_length_ + kMathEpsilon &&
        std::abs(point.y() - center_.y()) <= half_width_ + kMathEpsilon;
}

bool BBox2d::IsPointIn(const Vec2d &point) const{
    const double x0 = point.x();
    const double y0 = point.y();
    const double dx = std::abs(heading_cos_ * x0 + heading_sin_ * y0);
    const double dy = std::abs(-heading_sin_ * x0 + heading_con_ * y0);
    return dx <= half_length + kMathEpsilon && dy <= half_width_ + kMathEpsilon;
}
