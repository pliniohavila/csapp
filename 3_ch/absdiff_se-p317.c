long lt_cnt = 0;
long ge_cnt = 0;

long absdiff_se_1(long x, long y)
{
  long t = x < y;
  long result;
  
  if (t) goto true;
  ge_cnt++;
  result = x - y;
  goto done;

true:
  lt_cnt++;
  result = y - x;

done:
  return result;
}

long absdiff_se(long x, long y)
{
  long result;
  
  if (x < y) goto true;
  result = x - y;
  goto done;

true:
  result = y - x;

done:
  return result;
}