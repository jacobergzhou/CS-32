void removeOdds(vector<int>& v)
{
    vector<int>::iterator p;
    for(p = v.begin(); p != v.end(); )
    {
        if(*p % 2 == 1)
        {
            p = v.erase(p);
            continue;
        }
        p++;
    }
}
