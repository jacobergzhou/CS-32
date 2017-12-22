void removeBad(list<Movie*>& li)
{
    list<Movie*> :: iterator p;
    for(p = li.begin(); p != li.end();)
    {
        if((*p)->rating() < 50)
        {
            destroyedOnes.push_back((*p)->rating());
            p = li.erase(p);
            continue;
        }
        p++;
    }
}
