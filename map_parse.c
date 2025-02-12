int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	extension_valid(char *file_name)
{
	int	i;
		
	i = ft_strlen(file_name);
	if (file_name[i-1] == 'r' && file_name[i-2] == 'e'
		&& file_name[i-3] == 'b' && file_name[i-4] == '.')
		return (1);
	write(1, "Invalid extension", 17);  
	return (0);
}

int	file_to_map(char *route, t_data *data)
{
	int	fd;
	
	if (extension_valid == 0)
		return (0);
	fd = open(route, O_RDONLY);
	if (fd < 0)
		return (write(1, "Error while opening file", 24), 0);
	data->row_nbr = row_counter(fd);//**
	close(fd);
	fd = open(route, O_RDONLY);
	data->map = map_getter(route);//**
	close(fd);
	
}
