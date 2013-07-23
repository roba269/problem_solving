processIt :: String -> String
processIt wd =
  if length wd > 10
    then [head wd] ++ (show $ length wd - 2) ++ [last wd] 
    else wd

main = do
  str <- getContents
  let
    wds = tail $ lines str
  putStrLn $ unlines $ map processIt wds 
