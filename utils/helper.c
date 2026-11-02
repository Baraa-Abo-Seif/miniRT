double	clamp_unit(double val)
{
	if (val < -1.0)
		return (-1.0);
	if (val > 1.0)
		return (1.0);
	return (val);
}
