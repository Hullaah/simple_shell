#include "main.h"
/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 * @src: memory area to copy from
 * @dest: memory area to copy to
 * @n: number of bytes to be copied
 * Return: memory copied to
*/
void *_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	char *dst_ptr = dest;
	const char *src_ptr = src;

	for (i = 0; i < n; i++)
		dst_ptr[i] = src_ptr[i];
	return (dest);
}
/**
 * _realloc - works just like the standard library c realloc
 * @ptr: pinter to be reallocated
 * @old_size: old allocated size
 * @new_size: new allocated size
 * Return: pointer to allocated memory
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *tmp;


	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		/*free(ptr);*/
		ptr = malloc(new_size);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	tmp = malloc(new_size);
	if (tmp == NULL)
		return (NULL);
	if (old_size < new_size)
		_memcpy(tmp, ptr, old_size);
	else
		_memcpy(tmp, ptr, new_size);
	free(ptr);
	ptr = tmp;
	return (tmp);
}
