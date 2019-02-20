# include "lem_in.h" 

t_path      *add_path(t_path *path, t_list *list)
{
    t_path     *new;
    t_path     *begin;

    if (!path)
    {
        path = (t_path *)malloc(sizeof(t_path));
        path->path = copy_list(list);
        path->length = size_list(list);
        path->waitlist = 0;
        path->next = NULL;
        return (path);
    }
    begin = path;
    new = (t_path *)malloc(sizeof(t_path));
    new->path = copy_list(list);
    new->length = size_list(list);
    new->waitlist = 0;
    new->next = NULL;
    while (path->next)
        path = path->next;
    path->next = new;
    return (begin);
}

t_path      *sort_path(t_path *path)
{
  t_path    *head;
  t_list    *tmp_list;
  int       tmp_length;

  head = path;
  while (path && path->next)
  {
    if (path->length > path->next->length)
    {
      tmp_list = path->path; 
      tmp_length = path->length;
      path->path = path->next->path;
      path->length = path->next->length;
      path->next->path = tmp_list;
      path->next->length = tmp_length;
      path = head;
    }
    else
      path = path->next;
  }
  path = head;
  return (path);
}