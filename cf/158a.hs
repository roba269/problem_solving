main = do
  str <- getContents
  let
    n:k:scores = map read (words str)
    res = length $ filter (\x->x>0&&x>=scores!!(k-1)) scores
  putStrLn $ show res
